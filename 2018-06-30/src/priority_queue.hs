
data HTree a = Nil
             | Node Int a (HTree a) (HTree a)

merge :: Ord a => HTree a -> HTree a -> HTree a
merge Nil Nil = Nil
merge Nil t = t
merge t Nil = t
merge l@(Node _ x ll lr) r@(Node _ y rl rr) = if x > y then make x ll (merge lr r) else make y rl (merge l rr)
  where
    make x l r = if rank l > rank r then Node (rank r + 1) x l r else Node (rank l + 1) x r l
    rank Nil = 0
    rank (Node n _ _ _) = n

type PQueue a = HTree a

insert :: Ord a => a -> PQueue a -> PQueue a
insert v q = merge q (Node 1 v Nil Nil)

extract :: Ord a => PQueue a -> (a, PQueue a)
extract Nil = error "empty queue"
extract (Node _ v l r) = (v, merge l r)

data Inst a = Insert a
            | Extract
            | End

parseInst :: Read a => [String] -> Inst a
parseInst ["insert", v] = Insert (read v)
parseInst ["extract"] = Extract
parseInst _ = End

eval :: (Show a, Ord a) => [Inst a] -> PQueue a -> IO ()
eval (Insert v:is) q = eval is (insert v q)
eval (Extract:is) q = let (v,q') = extract q in print v >> eval is q'
eval _ _ = return ()

main :: IO ()
main = do
  insts <- map (parseInst . words) . lines <$> getContents
  eval insts (Nil :: PQueue Int)
