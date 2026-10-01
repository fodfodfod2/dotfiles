local M = {
  "olimorris/onedarkpro.nvim",
  lazy = false, -- Loads this plugin at the beginning
  priority = 1000, 
}

function M.config()
  require("onedarkpro").setup({
    highlights = {
      comment = {
        fg = "#0000FF",
        bold = true,
      },
      ["@lsp.type.type.c"] = {
        fg = "#880088",
      },
      ["@lsp.type.macro.c"] = {
        fg = "#6666FF",
        italic = true,
        bold = true,
      },
      ["@lsp.type.enumMember.c"] = {
        fg = "#6666FF",
        bold = true,
      },
      ["@variable.c"] = {
        fg = "#6666FF",
        italic = true,
      },
      ["@lsp.type.parameter"] = {
        fg = "#AA00AA",
        italic = true,
      },
      ["@lsp.type.method.c"] = {
        fg = "#770077",
      },
      ["@type.qualifier.c"] = {
        fg = "#FF4D00",
      },
    },
  })
  vim.cmd.colorscheme "onedark_dark"
end

return M
