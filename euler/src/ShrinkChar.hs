{-# LANGUAGE GeneralizedNewtypeDeriving #-}
module ShrinkChar where

import Data.Char
import System.Random
import Test.QuickCheck hiding ((.&.))

newtype BigChar = Big Char
                deriving (Eq, Show, Random)

instance Arbitrary BigChar where
  arbitrary = choose (Big '0', Big '\x10FFFF')
  shrink (Big c) = map Big (shrinkChar c)

{- Write a body for shrinkChar below.

   Suggested pattern:
   0, c * 0.5, c * 0.75, c * 0.875, ... -}
shrinkChar :: Char -> String
shrinkChar c = map chr (s $ ord c)

s :: Integral a => a -> [a]
s c = s' where s' = 0 : map ((`quot` 2) . (+ c)) s'
