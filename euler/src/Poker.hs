module Poker where

import           Data.Char  (digitToInt, isDigit)
import           Data.List  (sort)
import           Data.Maybe (isJust, mapMaybe)

data CardType = Heart | Spade | Diamond | Club deriving (Eq, Show)
data Card = Card CardType Int deriving Show
data Rank = High Int Int Int Int Int |
            Pair Int Int Int Int |
            Pair2 Int Int Int |
            Kind Int Int Int |
            Straight Int |
            Flush Int Int Int Int Int |
            Full Int Int |
            FKind Int Int |
            StraightF Int |
            Royal deriving (Eq, Ord, Show)

cardNum :: Card -> Int
cardNum (Card _ i)   = i

toNum :: Char -> Maybe Int
toNum 'A' = Just 14
toNum 'K' = Just 13
toNum 'Q' = Just 12
toNum 'J' = Just 11
toNum 'T' = Just 10
toNum n   | isDigit n = Just $ digitToInt n
toNum _   = Nothing

toPoker :: String -> Maybe Card
toPoker [a,'H'] = fmap (Card Heart) (toNum a)
toPoker [a,'S'] = fmap (Card Spade) (toNum a)
toPoker [a,'D'] = fmap (Card Diamond) (toNum a)
toPoker [a,'C'] = fmap (Card Club) (toNum a)
toPoker _       = Nothing

compareRank :: [Rank] -> [Rank] -> Ordering
compareRank (r1:l1) (r2:l2)
  | r1 == r2 = compareRank l1 l2
  | r1 < r2 = LT
  | otherwise = GT
compareRank (_:_) [] = LT
compareRank [] (_:_) = GT
compareRank [] [] = EQ

ranks :: [Card] -> [Rank]
ranks cards = mapMaybe (\f -> f cards) rankRules

isCont :: [Int] -> Bool
isCont values = isSortedCont (sort values)
  where isSortedCont []           = True
        isSortedCont [_]          = True
        isSortedCont [2,3,4,5,14] = True
        isSortedCont (x:xs@(y:_)) = x + 1 == y && isSortedCont xs


isSameSuitBy :: [Card] -> Card -> Bool
isSameSuitBy [] _                         = True
isSameSuitBy (Card t1 _:xs) y@(Card t2 _) = t1 == t2 && isSameSuitBy xs y

isFlush :: [Card] -> Bool
isFlush []     = True
isFlush (x:xs) = isSameSuitBy xs x

isStraight :: [Card] -> Bool
isStraight = isCont . map cardNum

royal :: [Card] -> Maybe Rank
royal cards
  | isFlush cards
    && isStraight cards
    && sort (map cardNum cards) == [10,11,12,13,14] = Just Royal
royal _ = Nothing
hasN :: Int -> [Int] -> Int -> Bool
hasN v values n = n == length (filter (== v) values)


straightFlush :: [Card] -> Maybe Rank
straightFlush cards
  | isStraight cards
    && isFlush cards = Just $ StraightF . maximum $ map cardNum cards
straightFlush _ = Nothing

fourKind :: [Card] -> Maybe Rank
fourKind cards
  | hasN max' numbers 4 = Just (FKind max' min')
  | hasN min' numbers 4 = Just (FKind min' max')
  where numbers = map cardNum cards
        max' = maximum numbers
        min' = minimum numbers
fourKind _ = Nothing

fullHouse :: [Card] -> Maybe Rank
fullHouse cards
  | hasN max' numbers 3 && hasN min' numbers 2 = Just (Full max' min')
  | hasN min' numbers 3 && hasN min' numbers 2 = Just (Full min' max')
  where numbers = map cardNum cards
        max' = maximum numbers
        min' = minimum numbers
fullHouse _ = Nothing

flush :: [Card] -> Maybe Rank
flush cards | isFlush cards = Just $ flist numbers
            where numbers = sort (map cardNum cards)
                  flist [a,b,c,d,e] = Flush e d c b a
                  flist _           = error "impossible"
flush _ = Nothing

straight :: [Card] -> Maybe Rank
straight cards | isStraight cards = Just $ Straight (m' numbers)
  where numbers = sort $ map cardNum cards
        m' [14,2,3,4,5] = 5
        m' ns           = maximum ns
straight _ = Nothing

kind :: [Card] -> Maybe Rank
kind cards
  | hasN a numbers 3 = Just (klist a $ sort $ filter (/= a) numbers)
  | hasN b numbers 3 = Just (klist b $ sort $ filter (/= b) numbers)
  | hasN c numbers 3 = Just (klist b $ sort $ filter (/= c) numbers)
  where numbers = map cardNum cards
        a:b:c:_ = numbers
        klist a' [m,n] = Kind a' n m
        klist _ _      = error "impossible"
kind _ = Nothing

getPair :: [Int] -> [Int]
getPair [] = []
getPair (x:xs) | x `elem` xs = x : getPair (filter (/= x) xs)
               | otherwise = getPair xs

divideTwoPair :: [Int] -> Maybe (Int, Int, Int)
divideTwoPair numbers
  | length pairs == 2 &&
    length left == 1 = Just (b, a, head left)
  where pairs = getPair numbers
        [a,b] = sort pairs
        left = filter (\t -> t /= a && t /= b) numbers
divideTwoPair _ = Nothing

pair2 :: [Card] -> Maybe Rank
pair2 cards | isJust res = fmap (\(a,b,c) -> Pair2 a b c) res
  where res = divideTwoPair (map cardNum cards)
pair2 _ = Nothing

pair :: [Card] -> Maybe Rank
pair cards
  | hasN a numbers 2 = Just (plist2 a $ sort $ filter (/= a) numbers)
  | hasN b numbers 2 = Just (plist2 b $ sort $ filter (/= b) numbers)
  | hasN c numbers 2 = Just (plist2 c $ sort $ filter (/= c) numbers)
  | hasN d numbers 2 = Just (plist2 d $ sort $ filter (/= d) numbers)
  where numbers = map cardNum cards
        a:b:c:d:_ = numbers
        plist2 a' [m,n,l] = Pair a' l n m
        plist2 _ _        = error "impossible"
pair _ = Nothing

high :: [Card] -> Maybe Rank
high cards = Just $ hlist (sort $ map cardNum cards)
  where hlist [a,b,c,d,e] = High e d c b a
        hlist _           = error "impossible"

rankRules :: [[Card] -> Maybe Rank]
rankRules = [royal,
             straightFlush,
             fourKind,
             fullHouse,
             flush,
             straight,
             kind,
             pair2,
             pair,
             high]
