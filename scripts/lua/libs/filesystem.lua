
local filesystem = {}

function filesystem.mkdir(a_path)
    os.execute("mkdir " .. a_path)
    return true
end

function filesystem.new_item(file_name, file_content)
    local command = string.format(
    [[powershell -Command "New-Item -Path . -Name '%s' -ItemType 'file' -Value '%s'"]],
    file_name,
    file_content
    )
    -- Execute the command and check success
    local success = os.execute(command)

    -- Check execution result and handle error
    if not success then
        print(string.format("Failed to create file '%s'.", file_name))
        return false
    end
    return true
end

return filesystem
