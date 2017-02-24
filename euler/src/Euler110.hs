module Euler110 where
import Control.Monad.State
import Data.List
import qualified Data.Map as M

primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173]

series _ 1 = [[0]]
series xs n = [x:ps|x<-xs,ps<-series [0..x] (n-1)]

sumpri x = product $zipWith (^) primes x
distinct = foldl1 (\x y->2*x*y+x+y)
prob x y = minimum [(sumpri m,m)|m<-series [1..4] x, (>y) $ distinct m]

main = print$prob 25 (4*(10^6))
