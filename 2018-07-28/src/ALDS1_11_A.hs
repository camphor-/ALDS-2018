{-# LANGUAGE TypeApplications #-}
import Control.Monad

main :: IO ()
main = do
  n <- readLn
  ms <- replicateM n $ do
    i:_:xs <- map (read @Int) . words <$> getLine
    return (i,xs) 
  let format = unlines . map (unwords . map show)
  putStr . format $ trans n ms

trans :: Int -> [(Int,[Int])] -> [[Int]]
trans n g = [[if i `elem` ch then 1 else 0 | i <- [1..n]] | (_,ch) <- g]
