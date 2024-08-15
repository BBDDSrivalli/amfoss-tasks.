import System.IO

createInputFile :: IO ()
createInputFile = do
    writeFile "input.txt" "This is a test string for Sub-Task 2."

readAndWrite :: IO ()
readAndWrite = do
    content <- readFile "input.txt"
    putStrLn "Content read from input.txt:"
    putStrLn content

    writeFile "output.txt" content
    putStrLn "Content successfully copied from input.txt to output.txt"

    appendFile "output.txt" "\nAppending new content to output.txt."

    updatedContent <- readFile "output.txt"
    putStrLn "Updated content of output.txt:"
    putStrLn updatedContent

main :: IO ()
main = do
    createInputFile
    readAndWrite
