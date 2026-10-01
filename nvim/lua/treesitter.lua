local M = {
    "nvim-treesitter/nvim-treesitter",
    build = ":TSUpdate",
    main = 'nvim-treesitter.config',
    opts = {
      ensure_installed = { 'lua', 'c', 'bash', 'c++'},
      highlight = { enable = true },
    },
  lazy = false,
}

function M.config()

end

return M
