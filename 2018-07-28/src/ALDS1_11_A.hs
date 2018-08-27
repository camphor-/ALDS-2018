{-# LANGUAGE TypeApplications #-}
import Control.Monad

main :: IO ()
main = do
  n <- readLn
  ms <- replicateM n $ do
    i:_:xs <- map (read @Int) . words <$> getLine
    return (i,xs) 
  return ()
