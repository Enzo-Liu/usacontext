-- SaveMoney.hs ---
--
-- Filename: SaveMoney.hs
-- Description:
-- Author:
-- Maintainer:
-- Created: Fri May 15 16:15:41 2015 (+0800)
-- Version:
-- Package-Requires: ()
-- Last-Updated: Fri May 15 16:18:33 2015 (+0800)
--           By: enzo-liu
--     Update #: 7
-- URL:
-- Doc URL:
-- Keywords:
-- Compatibility:
--
--

-- Commentary:
--
--
--
--

-- Change Log:
--
--
--
--
-- This program is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or (at
-- your option) any later version.
--
-- This program is distributed in the hope that it will be useful, but
-- WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-- General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
--
--

-- Code:
import Control.Monad             (guard)
import Control.Monad.Trans.State
import Data.List                 (foldl')

asNumber :: [Int] -> Int
asNumber = foldl' (\t o -> t*10 + o) 0

select :: [a] -> [(a, [a])]
select []     = []
select (x:xs) = (x,xs) : [(y,x:ys) | (y,ys) <- select xs]

main :: IO ()
main = print . flip evalStateT [0..9] $ do
    s <- StateT select
    e <- StateT select
    n <- StateT select
    d <- StateT select
    m <- StateT select
    o <- StateT select
    r <- StateT select
    y <- StateT select
    guard $ s /= 0 && m /= 0
    let send  = asNumber [s,e,n,d]
        more  = asNumber [m,o,r,e]
        money = asNumber [m,o,n,e,y]
    guard $ send + more == money
    return (send, more, money)


--
-- SaveMoney.hs ends here
