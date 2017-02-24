module Euler164 where

-- How many 20 digit numbers n (without any leading zero) exist such
-- that no three consecutive digits of n have a sum greater than 9?

sumBelow9 = [(x,y,z) | x<-[1..9],y<-[0..9],z<-[0..9],x+y+z<=9]

ways :: Int -> Int -> Int -> Integer
ways _ 0 _ = 1
ways f 1 s = fromIntegral $9-f-s+1
ways f l s = sum . map (ways s (l-1)) $ [x | x<-[0..9],x+f+s<=9]

divBy :: Integral a => a -> [a] -> Maybe [a]
divBy numerator denominators =
    mapM (numerator `safeDiv`) denominators
    where safeDiv _ 0 = Nothing
          safeDiv x y = return $x `div` y
