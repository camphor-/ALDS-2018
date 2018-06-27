{-# LANGUAGE BangPatterns #-}
import Control.Monad

data BSTree a = Nil
              | Node { key :: a
                     , left :: BSTree a
                     , right :: BSTree a
                     }

insert :: Ord a => a -> BSTree a -> BSTree a
insert v Nil = Node v Nil Nil
insert v (Node v' l r) | v < v' = Node v' (insert v l) r
                       | otherwise = Node v' l (insert v r)

find :: Eq a => a -> BSTree a -> Bool
find v Nil = False
find v (Node v' l r) | v == v' = True
                     | otherwise = find v l || find v r

delete :: Eq a => a -> BSTree a -> BSTree a
delete v Nil = Nil
delete v (Node v' l r) | v == v' = merge l r
                       | otherwise = Node v' (delete v l) (delete v r)
  where
    merge Nil Nil = Nil
    merge Nil r = r
    merge l Nil = l
    merge l r = let x = findMin l in Node x l (delete x r)

    findMin (Node x Nil _) = x
    findMin (Node _ l _) = findMin l

preOrdTrav :: BSTree a -> [a]
preOrdTrav Nil = []
preOrdTrav (Node v l r) = [v] ++ preOrdTrav l ++ preOrdTrav r

inOrdTrav :: BSTree a -> [a]
inOrdTrav Nil = []
inOrdTrav (Node v l r) = inOrdTrav l ++ [v] ++ inOrdTrav r

data Inst a = Insert a
            | Find a
            | Delete a
            | Print

parseInst :: Read a => [String] -> Inst a
parseInst ["print"] = Print
parseInst ["insert", v] = Insert (read v)
parseInst ["find", v] = Find (read v)
parseInst ["delete", v] = Delete (read v)
parseInst _ = error "invalid inst"

eval :: (Show a, Ord a) => [Inst a] -> BSTree a -> IO ()
eval [] _ = return ()
eval (Print:is) !t = let puts = putStrLn . (" "++) . unwords . map show
                     in puts (inOrdTrav t) >> puts (preOrdTrav t) >> eval is t
eval (Insert v:is) !t = eval is (insert v t)
eval (Find v:is) !t = putStrLn (if find v t then "yes" else "no") >> eval is t
eval (Delete v:is) !t = eval is (delete v t)

main :: IO ()
main = do
  n <- readLn
  insts <- replicateM n $ parseInst . words <$> getLine
  eval insts (Nil :: BSTree Int)
