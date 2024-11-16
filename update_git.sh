#!/bin/bash

# Navigate to your project directory
cd "D:/college/placement/digri/Digri-code-chalenges" || exit

# Stage all changes
git add .

# Commit the changes with the current date
current_date=$(date +"%Y-%m-%d")
git commit -m "Updated daily challenges for $current_date"

# Push to the remote repository
git push origin main
