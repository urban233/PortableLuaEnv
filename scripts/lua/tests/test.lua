local filesystem = require("filesystem")

local build_dir = "build"
-- local relative_path = [[subfolder\file.txt]]
-- filesystem.mkdir(build_dir)
local file_name = "testfile.txt"
local file_content = "This is a text string."
if not filesystem.new_item(file_name, file_content) then
    print("An error occurred during the creation of the test file!")
end
print("Hi Lua.")

-- Prompt the user
print("Please press any key to exit ...")
-- Read input from the user
local input = io.read()
