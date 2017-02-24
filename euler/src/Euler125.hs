module Euler125 where
import Data.List

palid :: (Show a, Read a, Eq a) => a -> Bool
palid n = n == (read.reverse.show) n

conSum :: Integer -> [Integer]
conSum i = gen (i+2) (i^2+(i+1)^2)
  where gen i start = start:gen (i+1) (i^2+start)

prob :: Integer -> Integer
prob n = sum.nub.concat
         $map (filter palid.takeWhile (<n) .conSum) [1..m]
  where m = ceiling $sqrt (fromIntegral n)

main :: IO ()
main = print.prob $ (10^8)
