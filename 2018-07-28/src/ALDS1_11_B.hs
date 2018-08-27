import Control.Monad
import Control.Monad.Trans.RWS
import Data.List (sort)
import qualified Data.IntMap as M

-- 隣接リスト表現
type Graph = M.IntMap [Int]
-- Reader: Graph
-- Writer: ノードID、訪問時刻、完了時刻
-- State: 現在時刻、訪問済ノード
type VM = RWS Graph [(Int,Int,Int)] (Int,[Int])

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

format :: [(Int,Int,Int)] -> String
format xs = unlines $ [unwords $ map show [i,t0,t1] | (i,t0,t1) <- xs]

solve :: Graph -> [(Int,Int,Int)]
solve g = sort $ snd $ execRWS (dfs 1) g (0,[])

-- 再帰呼び出しによるDFS
dfs :: Int -> VM ()
dfs i = do
  b <- visited i
  unless b $ do
    t <- getTime
    ch <- getChild i
    mapM_ dfs ch
    t' <- getTime
    tell [(i,t,t')]

getTime :: VM Int
getTime = do
  modify (\(t,xs) -> (t+1,xs))
  fst <$> get

getChild :: Int -> VM [Int]
getChild i = reader (\g -> g M.! i)

visited :: Int -> VM Bool
visited i = do
  xs <- snd <$> get
  let res = i `elem` xs
  unless res $ modify (\(t,ns) -> (t,i:ns))
  return res
