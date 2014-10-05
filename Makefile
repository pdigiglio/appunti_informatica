.PHONY: clean

# options to pass
rm_options = --verbose --recursive --force
# target extensions to remove
rm_targets = *.lof *.lot *.lol *.aux *.log *.synctex.gz *.out *.toc *.run.xml *.bbl *-blx.bib *.idx

# find recursively all files to remove in subdirectories
rm_files := $(foreach tmp, $(rm_targets), $(shell find -type f -name '$(tmp)'))

clean:
	@ echo "\n[`tput bold``tput setab 1`clean`tput sgr0`] `tput bold`rm`tput sgr0` " \
		   "`tput setaf 3`$(rm_options)`tput sgr0` $(rm_targets)\n"
	@ rm $(rm_options) $(rm_files)
