import Control.Monad
import Control.Monad.Trans.RWS
import qualified Data.IntMap as M

-- 隣接リスト表現
type Graph = M.IntMap [Int]
type Stack = [Int]
-- Reader: Graph
-- Writer: ノードID
-- State: スタック、訪問済ノード
type VM = RWS Graph [Int] (Stack,[Int])

main :: IO ()
main = do
  g <- readGraph
  qs <- readQuestions
  mapM_ putStrLn [if solve g s t then "yes" else "no" | (s,t) <- qs]

getInts :: IO [Int]
getInts = map read . words <$> getLine

readGraph :: IO Graph
readGraph = do
  [n,m] <- getInts
  fs <- replicateM m $ do
    [i,c] <- getInts
    return (i,c)
  let g = M.fromList [(i,[]) | i <- [0..n-1]]
  return $ buildGraph g fs

buildGraph :: Graph -> [(Int,Int)] -> Graph
buildGraph = foldr (\(i,x) acc -> M.adjust (x:) i acc)

readQuestions :: IO [(Int,Int)]
readQuestions = do
  n <- readLn
  replicateM n $ do
    [s,t] <- getInts
    return (s,t)

solve :: Graph -> Int -> Int -> Bool
solve g s t = t `elem` ns
  where ns = snd $ execRWS dfs g ([s],[])

dfs :: VM ()
dfs = do
  b <- isEnd
  unless b $ do
    x <- pop
    visited x
    ch <- getChild x
    push ch
    dfs

getChild :: Int -> VM [Int]
getChild i = reader (\g -> g M.! i)

isEnd :: VM Bool
isEnd = do
  s <- fst <$> get
  return $ null s

pop :: VM Int
pop = do
  (x:s,vs) <- get
  put (s,vs)
  return x

push :: [Int] -> VM ()
push xs = do
  (s,vs) <- get
  let xs' = filter (`notElem` vs) xs
  put (xs' ++ s, vs)

visited :: Int -> VM ()
visited x = do
  (s,vs) <- get
  when (x `notElem` vs) $ do
    put (s,x:vs)
    tell [x]
