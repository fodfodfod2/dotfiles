vim.g.mapleader = " "

vim.opt.number = true
vim.opt.ruler = true

vim.opt.tabstop = 2
vim.opt.shiftwidth = 2

vim.opt.autoindent = true
vim.opt.smartindent = true

vim.opt.expandtab = true

vim.opt.hlsearch = true
vim.opt.incsearch = true

vim.opt.mouse = 'a'

vim.opt.scrolloff = 7
vim.opt.relativenumber = true
vim.opt.number = true

_G.custom_line_numbers = function()
  local rnu = vim.v.relnum
  local lnum = vim.v.lnum
  if rnu > 10 then
    return tostring(lnum)
  elseif rnu == 0 then
    return tostring(lnum)
  else
    return tostring(rnu)
  end
end

vim.opt.statuscolumn = "%=%{%v:lua.custom_line_numbers()%} "

vim.opt.list = true
vim.opt.listchars = {
	tab = ' 󰌒',
	trail = '·',
}

vim.opt.errorbells = false
vim.opt.visualbell = true

vim.opt.wrap = true

vim.opt.swapfile = true
vim.opt.backup = false
vim.opt.undofile = true
vim.opt.undodir = os.getenv("HOME") .. "/.vim/undodir"

vim.opt.updatetime = 50
vim.opt.colorcolumn = "80"
vim.opt.textwidth = 80
