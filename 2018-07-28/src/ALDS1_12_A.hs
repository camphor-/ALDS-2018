import Control.Monad.Trans.RWS
import Data.List
import Data.Ord
import qualified Data.IntMap as M
import Data.Monoid

type Graph = M.IntMap [(Int,Int)]
data Info = Info
  { visited :: [Int]
  , next :: [(Int,Int)]
  }
type VM = RWS Graph (Sum Int) Info

main :: IO ()
main = do
  g <- readGraph
  print $ solve g

readGraph :: IO Graph
readGraph = do
  _ <- getLine
  g <- map (map read . words) . lines <$> getContents
  return $ M.fromList [(i,[(j,w) | (j,w) <- zip [0..] xs, w > 0]) | (i,xs) <- zip [0..] g]

solve :: Graph -> Int
solve g = getSum . snd $ evalRWS mst g i0
  where i0 = Info [] [(0,0)]

mst :: VM ()
mst = do
  mn <- getNext
  case mn of
    Nothing -> return ()
    Just n -> visit n >> mst

getNext :: VM (Maybe (Int,Int))
getNext = do
  ns <- next <$> get
  return $ if null ns then Nothing else Just (minimumBy (comparing snd) ns)

visit :: (Int,Int) -> VM ()
visit (x,w) = do
  tell (Sum w)
  (Info vs ns) <- get
  let vs' = x:vs
  ys <- reader (M.!x)
  let ns' = filter (\(n,_) -> n `notElem` vs') (ys ++ ns)
  put (Info vs' ns')
