#!/usr/bin/env bash

# Function to check if a string is in kebab case
function is_kebab_case
{
    local input="$1"
    # Check if the string matches kebab case pattern
    if [[ "$input" =~ ^[a-z]+(-[a-z]+)*$ ]]; then
        echo true
    else
        echo false
    fi
}

base_commit=$(git rev-parse HEAD~1)
current_commit=$(git rev-parse HEAD)

changed_files=$(git diff --name-only $base_commit $current_commit)

echo "Non-kebab case file names: "
# Read the changed_files variable line by line
# assign the current line to the variable file_path
found=false
echo "$changed_files" | while read -r file_path; do
    # Extract file name from the path
    file_name=$(basename "$file_path")
    # Remove the extension from the file name
    file_name="${file_name%.*}"

    # Check if the file name is in kebab case
    if [[ $(is_kebab_case $file_name) = false ]]; then
        echo "$file_path"
        found=true
    fi
done

if [[ $found = false ]]; then
    echo "None! Well done! :)"
else
    echo "Please fix the above files!"
    return 1
fi