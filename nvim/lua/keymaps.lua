vim.keymap.set('n', '<leader>w', ':w<CR>')
vim.keymap.set("n", "<leader>pv", vim.cmd.Ex)
vim.keymap.del('n', 'Y')

-- fugitive
vim.keymap.set("n", "<leader>gs", vim.cmd.Git)

--- undotree
vim.keymap.set("n", "<leader>u", vim.cmd.UndotreeToggle)

-- shortcuts --
vim.api.nvim_create_user_command('W', 'w', {})
vim.cmd('cnoreabbrev rs restart')
