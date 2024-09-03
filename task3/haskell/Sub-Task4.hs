import System.IO

printPattern :: Int -> IO ()
printPattern n = do
    let half = (n + 1) `div` 2
    mapM_ (putStrLn . pattern half) [1..half]
    mapM_ (putStrLn . pattern half) [half + 1..n]

    writeFile "output.txt" (unlines (map (pattern half) [1..half] ++ map (pattern half) [half + 1..n]))
    putStrLn "Diamond pattern has been written to output.txt"

pattern :: Int -> Int -> String
pattern half i
    | i <= half = replicate (half - i) ' ' ++ replicate (i * 2 - 1) '*'
    | otherwise = replicate (i - half) ' ' ++ replicate ((half * 2 - i) * 2 - 1) '*'

main :: IO ()
main = do
    putStrLn "Enter the number of rows: "
    n <- readLn
    printPattern n
