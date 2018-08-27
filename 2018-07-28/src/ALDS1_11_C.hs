import Control.Monad
import Control.Monad.Trans.RWS
import Data.List (sort)
import qualified Data.IntMap as M
import qualified Data.Sequence as S

-- 隣接リスト表現
type Graph = M.IntMap [Int]
type Queue = S.Seq (Int,Int)
-- Reader: Graph
-- Writer: ノードID、距離
-- State: キュー、訪問済ノード
type VM = RWS Graph [(Int,Int)] (Queue,[Int])

main :: IO ()
main = do
  g <- readGraph
  putStr $ format $ solve g

readGraph :: IO Graph
readGraph = do
  n <- readLn
  g <- replicateM n $ do
    (i:_:ch) <- map read . words <$> getLine
    return (i,sort ch)
  return $ M.fromList g

format :: [(Int,Int)] -> String
format = unlines . map (\(i,d) -> show i ++ " " ++ show d)

-- この実装は手抜きである
-- たどり着けないノードに対する処理を行っていない
solve :: Graph -> [(Int,Int)]
solve g = sort $ snd $ execRWS bfs g (S.singleton (1,0),[])

bfs :: VM ()
bfs = do
  b <- isEnd
  unless b $ do
    x@(i,d) <- dequeue
    visited x
    ch <- getChild i
    enqueue d ch
    bfs

getChild :: Int -> VM [Int]
getChild i = reader (\g -> g M.! i)

isEnd :: VM Bool
isEnd = do
  q <- fst <$> get
  return $ S.null q

dequeue :: VM (Int,Int)
dequeue = do
  (x S.:<| q, vs) <- get
  put (q, vs)
  return x

enqueue :: Int -> [Int] -> VM ()
enqueue d xs = do
  (q,vs) <- get
  let xs' = filter (`notElem` vs) xs
      q' = foldl (\acc x -> acc S.|> (x,d+1)) q xs'
  put (q', vs)

visited :: (Int,Int) -> VM ()
visited x@(i,_) = do
  (q,vs) <- get
  when (i `notElem` vs) $ do
    put (q,i:vs)
    tell [x]
