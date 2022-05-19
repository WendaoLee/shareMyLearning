toDigits::Integer -> [Integer]
toDigits a
    | a / 10 == 0 && a%10 != 0 = (mod a 10) :[]
    | otherwise = (toDigits (a / 10)) : (mod a/10 10) : []