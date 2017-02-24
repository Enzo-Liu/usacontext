module Euler108 where
import Data.List

-- 1/n = 1/x + 1/y ; n -> (x,y) nx + ny = n(x,y)
sol :: Int -> [(Int,Int)]
sol n = sh (n+1) []
  where sh x acc
          | x>2*n = acc
          | r == 0 = sh (x+1) ((x,d):acc)
          | otherwise = sh (x+1) acc
          where (d,r) = (n*x) `quotRem` (x-n)

factor :: Int -> Int -> Maybe (Int,Int)
factor n x = let (d,r) = n `quotRem` x in
  if r == 0 then Just (x,d) else Nothing

factors :: Int -> [Int]
factors n = foldl (\a x->
                     case (factor n x) of
                       Nothing -> a
                       Just (x1,x2) -> nub$x1:x2:a) [] [1..ceiling.sqrt.fromIntegral$n]

solNum = length.sol

primePair :: Int -> Int -> Bool
primePair a b = gcd a b == 1

sol' n = (1,1):[(a,b)| a<-fs,b<-fs,a<b,primePair a b]
  where fs = factors n
solNum' = length.sol'

main = print . head . filter (\x->solNum' x>=1000) $[1000..]
