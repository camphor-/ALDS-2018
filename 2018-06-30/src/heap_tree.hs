{-# LANGUAGE TypeApplications #-}
{-# LANGUAGE TupleSections #-}

import Data.Bifunctor
import Data.List

data HTree a = Nil
             | Node a (HTree a) (HTree a)
  deriving Show

-- max ヒープ条件を満たすようにする
maxHeapify :: Ord a => HTree a -> HTree a
maxHeapify Nil = Nil
maxHeapify (Node x l r) = shift x (maxHeapify l) (maxHeapify r)
  where
    shift x Nil Nil = (Node x Nil Nil)
    shift x (Node y l r) Nil = if x > y then Node x (Node y l r) Nil else Node y (shift x l r) Nil
    shift x Nil (Node y l r) = if x > y then Node x Nil (Node y l r) else Node y Nil (shift x l r)
    shift x (Node y ll lr) (Node z rl rr)
      | x > (y `max` z) = Node x (Node y ll lr) (Node z rl rr)
      | y > (x `max` z) = Node y (shift x ll lr) (Node z rl rr)
      | z > (x `max` y) = Node z (Node y ll lr) (shift x rl rr)

-- 完全二分木の作成
mkHTree :: [a] -> HTree a
mkHTree = head . foldr build [] . levels
  where
    levels xs = unfoldr (\(n,ys) -> if null xs then Nothing else Just $ fmap (2*n,) (splitAt n ys)) (1,xs)
    build [] _ = []
    build (x:xs) [] = Node x Nil Nil : build xs []
    build (x:xs) [t] = Node x t Nil : build xs []
    build (x:xs) (l:r:res) = Node x l r : build xs res

flatten :: Ord a => HTree a -> [a]
flatten Nil = []
flatten (Node v l r) = v : merge (flatten l) (flatten r)
  where
    merge [] ys = ys
    merge xs [] = xs
    merge (x:xs) (y:ys) | x > y = x : merge xs (y:ys)
                        | otherwise = y : merge (x:xs) ys

main :: IO ()
main = do
  getLine
  xs <- map (read @Int) . words <$> getLine
  let res = flatten $ maxHeapify $ mkHTree xs
  putStrLn . unwords . map show $ res
