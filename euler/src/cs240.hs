{-# LANGUAGE DeriveDataTypeable #-}

module Cs240h where
import Control.Exception
import Data.Typeable

newtype MyError = MyError String deriving (Show, Typeable)
instance Exception MyError

catcher :: IO a -> IO (Maybe a)
catcher action = fmap Just action `catch` handler
    where handler (MyError msg) = do putStrLn msg; return Nothing

error' :: String -> a
error' a = throw (ErrorCall a)

undefined' :: a
undefined' =  error' "Prelude.undefined"

pureCatcher :: a -> IO (Maybe a)
pureCatcher a = (a `seq` return (Just a))
                `catch` \(SomeException _) -> return Nothing

seqList :: [a] -> b -> b
seqList xs b = foldr seq b xs

try' :: Exception e => IO a -> IO (Either e a)
try' a = fmap Right a `catch` (return . Left)

finally' :: IO a -> IO b -> IO a      -- cleanup always
finally' a b = seq b a

onException' :: IO a -> IO b -> IO a  -- after exception
onException' a b = seq b a
