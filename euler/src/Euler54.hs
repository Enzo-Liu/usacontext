{-# LANGUAGE OverloadedStrings #-}

-- Poker hands
-- https://projecteuler.net/problem=54
-- Problem 54

module Euler54 where

import           Poker
import           Data.Maybe (mapMaybe)
import           System.IO



getCards :: String -> ([Card],[Card])
getCards str = splitAt 5 $ mapMaybe toPoker $ words str

getRanks :: String -> ([Rank],[Rank])
getRanks str = (ranks c1, ranks c2)
  where (c1,c2) = getCards str

win :: String -> Bool
win str = GT == compareRank (ranks c1) (ranks c2)
  where (c1, c2) = getCards str

main :: IO ()
main = do
  handle <- openFile "/Users/enzo/Downloads/p054_poker.txt" ReadMode
  contents <- hGetContents handle
  print $ length . filter win . lines $ contents
