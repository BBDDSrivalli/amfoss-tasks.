Terminal-Chaos Journey
Part 1

I navigated to the Documents directory and accessed the Terminal-Chaos folder. Inside, I entered the Arrakis-dex directory and used the tree command to display its structure. By using cat, I found the parchment containing a message and a code.

Code:
#1 aHR0cHM6Ly9naXRo
<p style="color:blue;">This part was pretty easy to find!</p>
Part 2

I used git branch -r to display lightrealm and darkrealm branches. By navigating between these realms using git checkout, I explored the lightrealm and used tree and grep to find and decode 'Mistveil' and 'Moonbloom', which provided the code LnnmknnlLhrsdhk (by combining them both, then writing the letter before in its place and removing vowels).

Holy Spell: LnnmknnlLhrsdhk
<p style="color:blue;">Finding the Holy Spell raised my frustration. I used `grep`, `find` multiple times. Finally found - LnnmknnlLhrsdhk.</p>

Then navigated to the Light realm where I found the "Kharnok the Bloodforged.py." When I ran it, it asked me for the holy spell. I then fought with "Kharnok the Bloodforged" and unlocked the Celestial Veil Amulet.

Celestial Veil Amulet Code: CSigVmaroAn

I also found the Light Book in which I had my second code:
#2 dWIuY29tL2FtYW5ze
Part 3

Navigating to the Dark Realm I and II, I opened both chests using the Celestial Veil Amulet Code.

Darkbook Codes:

#3 Darkbook 1: GNhbGlidXIvVGVyb

#4 Darkbook 2: WluYWwtQ2hhb3MtR29kU3VpdGU=

Combining all four codes, I got the link:

aHR0cHM6Ly9naXRodWIuY29tL2FtYW5zeGNhbGlidXIvVGVybWluYWwtQ2hhb3MtR29kU3VpdGU=

Link: https://github.com/amansxcalibur/Terminal-Chaos-GodSuite
Part 4

I used the codes to find the GodSuite repository. I cloned it to continue with the next part of the task.
Part 5

Here I opened the commit history of GodSuite by using git log. Then to see the changes in the commits, I used the git show command. In the third commit, I found the link to the "To the Stars" git repository. Then I cloned it, used ls, and ran victory.py. Finally, I took a screenshot and uploaded it in the task2 folder.
Git Commands I Learned

    git status: Shows modified files.
    git add .: Stages all the files for commit.
    git commit -m "Example Message": Commits the staged changes with a message.
    git push: Pushes the local changes to the remote repository.
    git pull: Merges changes from the remote repository to the local branch.
    git branch: Lists all branches in the repository.
    git checkout <branch name>: Switches to a different branch.
    git clone <url>: Clones a repository from the given URL.
    git log: Shows the commit history.
    git show: Displays changes introduced by commits.
    git checkout <branch-from-where-you-want-to-copy> example.txt: Copies a file from another branch to the current branch.

Terminal Commands I Learned

    cd <directory_path>: Changes the current working directory.
    cd ../: Moves up one directory level.
    ls: Lists files and directories in the current directory.
    mkdir <directory_name>: Creates a new directory.
    rmdir <directory_name>: Deletes an empty directory.
    nano <file_name>: Opens the default text editor for file editing or creation.
    cat <file_name>: Displays the contents of a file.
    tree: Displays the directory structure in a tree-like format.
    echo -n <Base64EncodedStringHere> | base64 -d: Decodes Base64 encoded strings.
    python3 <script_name.py>: Runs a Python script using Python 3.


