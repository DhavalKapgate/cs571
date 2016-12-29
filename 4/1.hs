
mySum :: (Integral a) =>[a] -> a
mySum arr = sumodd 0 arr
	where sumodd n arr =
		if arr == []
			then n 
			else let x = head arr
				 xs = drop 2 arr
			      in if odd x
			     	 then sumodd (n+x) xs 	
				 else sumodd n xs 

main = do
	idata <- getContents
	putStrLn $ show $ mySum $ map (read :: String -> Int) $ lines idata



