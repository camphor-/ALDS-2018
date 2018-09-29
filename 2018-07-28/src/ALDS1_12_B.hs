import Control.Monad
import Control.Monad.Trans.RWS
import qualified Data.IntMap as M
import Data.List

type Graph = M.IntMap [(Int,Int)]
data Info = Info
  { visited :: [Int]
  , next :: M.IntMap Int
  }
type VM = RWS Graph [(Int,Int)] Info

main :: IO ()
main = do
  g <- readGraph
  putStr . format $ solve g

format :: [(Int,Int)] -> String
format xs = unlines [show i ++ " " ++ show w | (i,w) <- xs]

readGraph :: IO Graph
readGraph = do
  n <- readLn
  xs <- replicateM n $ do
    (k:_:vws) <- map read . words <$> getLine
    return (k,sp vws)
  return $ M.fromList xs

sp :: [Int] -> [(Int,Int)]
sp [] = []
sp (v:w:res) = (v,w):sp res

solve :: Graph -> [(Int,Int)]
solve g = sortOn fst . snd $ evalRWS dijkstra g i0
  where i0 = Info [] (M.singleton 0 0)

dijkstra :: VM ()
dijkstra = do
  mn <- getNext
  case mn of
    Nothing -> return ()
    Just n -> visit n >> dijkstra

getNext :: VM (Maybe (Int,Int))
getNext = do
  ns <- next <$> get
  return $ if null ns then Nothing else Just (findNext ns)

findNext :: M.IntMap Int -> (Int,Int)
findNext = M.foldlWithKey' (\(x0,w0) x1 w1 -> if w0 < w1 then (x0,w0) else (x1,w1)) (maxBound, maxBound)

visit :: (Int,Int) -> VM ()
visit (x,w) = do
  tell [(x,w)]
  (Info vs ns) <- get
  let vs' = x:vs
  ys <- reader (M.!x)
  let ns1 = foldr (\(y,v) t -> M.insertWith (\dw w0 -> w0 `min` (w+dw)) y v t) ns ys
      ns' = M.filterWithKey (\k _ -> k `notElem` vs') ns1
  put (Info vs' ns')
