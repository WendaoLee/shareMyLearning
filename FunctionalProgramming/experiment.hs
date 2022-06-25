lucky :: (Integral a) => a -> String
lucky x = case x of
  7 -> "test the polymorphic"
  x -> "sorry"

-- lucky :: (Integral a) => a -> String
-- lucky 7 ="test the polymorphic"
-- lucky x = "sorry"

-- With synatic sugar 'case'
-- case expression of pattern -> result
--                    pattern -> result
--                    pattern -> result
--                    ...

max' :: (Ord a) => a -> a -> a
max' a b
  | a > b = a
  | otherwise = b

cylinder :: (RealFloat a) => a -> a -> a
-- cylinder r h =
--     let sideArea = 2 * pi * r * h
--         topArea = pi * r ^2
--     in  sideArea + 2 * topArea
cylinder r h = sideArea + 2 * topArea
  where
    sideArea = 2 * pi * r * h
    topArea = pi * r ^ 2 --有一说一，这样子梃丑的哈哈哈哈

foo :: Integer -> Integer
foo 0 = 16
foo 1 
  | "Haskell" > "C++" = 3
  | otherwise         = 4
foo n
  | n < 0            = 0
  | n `mod` 17 == 2  = -43
  | otherwise        = n + 3

f :: Int -> Int -> Int -> Int
f x y z = x + y + z

ex17 = f 3 17 8

ex01 = Failure
ex02 = OK 3.4

data FailableDouble = Failure
                    | OK Double
  deriving Show

safeDiv :: Double -> Double -> FailableDouble
safeDiv _ 0 = Failure
safeDiv x y = OK (x / y)

hailstone :: Integer -> Integer
hailstone n
  | n `mod` 2 == 0 = n `div` 2
  | otherwise      = 3*n + 1

hailstoneSeq :: Integer -> [Integer]
hailstoneSeq 1 = [1]
hailstoneSeq n = n : hailstoneSeq (hailstone n)

y :: Integer -> Integer
y n = n + 1

g::Integer -> Integer
g n = n*n

test::Integer -> Integer
test a = (y.g)a

data Thing = Shoe 
           | Ship 
           | SealingWax 
           | Cabbage 
           | King
  deriving Show

data Person = Person String Int Thing
  deriving Show

baz :: Person -> String
baz p@(Person n _ _) = "The name field of (" ++ show p ++ ") is " ++ n