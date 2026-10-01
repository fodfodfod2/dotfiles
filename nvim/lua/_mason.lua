local M = {
  'williamboman/mason.nvim',
  lazy = false,
  dependencies = {
    'williamboman/mason-lspconfig.nvim',
    'nvim-lua/plenary.nvim',
  },
  opts = {
    ui = {
      icons = {
        package_installed = "✓",
        package_pending = "➜",
        package_uninstalled = "✗"
      }
    }
  },
}

M.servers = {
  "clangd",
  "lua_ls",
  "bashls",
}

function M.config(_, opts)
  require("mason").setup(opts)

  require("mason-lspconfig").setup {
    ensure_installed = M.servers,
    automatic_installation = true,
  }


end

return {
  {
    'saghen/blink.cmp',
    lazy = false, -- Load immediately
    dependencies = 'rafamadriz/friendly-snippets',
    version = 'v0.*', -- Use a stable release

    opts = {
      keymap = {preset = 'default',
                ['<CR>'] = { 'select_and_accept', 'fallback' },
      },
      sources = {
        default = { 'lsp', 'path', 'snippets', 'buffer' },
      },
    },
  },
  {
    "neovim/nvim-lspconfig",
    lazy = false, -- Ensure it loads on startup
  },
  M,
}
