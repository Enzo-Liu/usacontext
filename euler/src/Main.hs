{-# LANGUAGE RecursiveDo #-}

module Main where
import Control.Monad.Fix(MonadFix)

main :: IO ()
main = print "sdf"

nthFib :: Int -> Integer
nthFib n = fibList !! n
    where fibList = 1 : 1 : zipWith (+) fibList (tail fibList)

fix :: (a -> a) -> a
fix f = let x = f x in x

nthFib' :: Num a => Int -> a
nthFib' n = fibList !! n
    where fibList = fix $ \l -> 1 : 1 : zipWith (+) l (tail l)

oneTwo :: (MonadFix m) => m (Int, Int)
oneTwo = do
  rec x <- return (1, snd y)
      y <- return (fst x, 2)
  return (fst y, snd x)
