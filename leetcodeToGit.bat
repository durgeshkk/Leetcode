@echo off
cd E:\Leetcode

@REM :: Assuming you've already initialized a Git repository
@REM git clone https://github.com/durgeshkk/Leetcode
@REM echo Cloned

git checkout -b feature
echo Feature created
git add .
echo Files Added
git commit -m "Leetcode Last Contest Solutions Added"
git push origin feature
echo Push Done, PR Raised
