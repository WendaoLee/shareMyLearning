-- lucky :: (Integral a) => a -> String
-- lucky 7 ="test the polymorphic"
-- lucky x = "sorry"

-- With synatic sugar 'case'
-- case expression of pattern -> result  
--                    pattern -> result  
--                    pattern -> result  
--                    ...  

lucky :: (Integral a) => a -> String
lucky x = case x of 7 -> "test the polymorphic"
                    x -> "sorry"

max' :: (Ord a) => a -> a -> a
max' a b 
      | a > b = a
      | otherwise = b

cylinder :: (RealFloat a) => a -> a -> a  
-- cylinder r h = 
--     let sideArea = 2 * pi * r * h  
--         topArea = pi * r ^2  
--     in  sideArea + 2 * topArea  
cylinder r h = sideArea + 2*topArea
                  where sideArea = 2*pi*r*h
                        topArea = pi*r^2 --有一说一，这样子梃丑的哈哈哈哈



