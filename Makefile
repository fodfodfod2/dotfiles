CUR_DIR := $(pwd)

.PHONY: default list nvim sway

default:
	@echo "No configs specified, do make NAME to copy NAME config (e.g. make nvim copies nvim configs)"
	@echo "Use make list to see all available configs"
	@echo "All files will be backed up into ./backup/NAME"

list:
	@echo "AVAILABLE CONFIGS"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-15s\033[0m %s\n", $$1, $$2}'

nvim: ## Nvim config
	-mv -f ~/.config/$@ $(CUR_DIR)/backup/$@
	ln -sf $(CUR_DIR)/$@ ~/.config/

sway: ## Sway config
	-mv -f ~/.config/$@ $(CUR_DIR)/backup/$@
	ln -sf $(CUR_DIR)/$@ ~/.config/



