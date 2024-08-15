printPattern :: Int -> IO ()
printPattern n = do
    putStrLn "Pattern 1"

    let half = (n + 1) `div` 2

    mapM_ putStrLn [replicate (half - i) ' ' ++ replicate ((i * 2) - 1) '*' | i <- [1..half]]
    mapM_ putStrLn [replicate (i - half) ' ' ++ replicate ((n + 1 - i) * 2 - 1) '*' | i <- [half + 1..n]]

main :: IO ()
main = do
    putStrLn "Enter the number of rows:"
    input <- getLine
    let n = read input :: Int

    printPattern n
