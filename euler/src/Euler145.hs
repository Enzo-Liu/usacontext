module Euler145 where

reverNum :: (Show a, Read a, Eq a) => a -> a
reverNum = read.reverse.show

reversible n = True

main = print "sdf"
