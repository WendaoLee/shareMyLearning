toDigits::Integer -> [Integer]
toDigits a
    | a <= 0 = []
    | a `div` 10 == 0 && a `mod` 10 /= 0 = [mod a 10]
    | otherwise = toDigits (a `div` 10) ++ [mod a 10]

toDigitsRev::Integer -> [Integer]
toDigitsRev a
    | a <= 0 = []
    | a `div` 10 == 0 && a `mod` 10 /= 0 = [mod a 10]
    | otherwise = mod a 10 : toDigitsRev (a `div` 10) 

-- (.) means f(g(x)).For instance,(f.g)x
-- In this section,it can be read as:doubleEveryOther(x)=reverse(zipWith(* [1,2..] reverse(x)))
-- The last ele-function should has the same reflection as the ori-function.Example:
--                                                                                  doubleEveryOther::[Integer] -> [Integer]
--                                                                      so like the reverse::[a] -> [a]
doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther = reverse . zipWith (*) oneTwo . reverse where
    oneTwo = 1 : 2 : oneTwo

-- Can be read as sumDigits(a)=sum(map(sum(digits(a))))
-- $ define the right para has higher precedence than the left.
sumDigits :: [Integer] -> Integer
sumDigits a = sum $ map (sum.toDigits) a

-- Integer -> [Integer] -> Interger -> Bool
-- sumDigits(doubleEveryOther(toDigits(x)))
validate :: Integer -> Bool
validate a
    | calSum a `mod` 10 == 0 = True
    | otherwise = False
    where calSum = sumDigits . doubleEveryOther.toDigits

type Peg = String
type Move = (Peg, Peg)
hanoi::Integer -> Peg -> Peg ->Peg -> [Move]
hanoi n src goal tmp
  | n <= 0    = []
  | n == 1    = [(src, goal)]
  | otherwise = hanoi (n-1) src tmp goal ++ hanoi 1 src goal tmp
                ++ hanoi (n-1) tmp goal src

