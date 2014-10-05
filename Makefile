SHELL = bash

# Document data(s)
document = Informatica
bibliografia = bibliografia

.PHONY: clean distclean dist biblioclean biblio indexclean index

# options to pass
rm_options = --verbose --recursive --force

# target extensions to remove
biblio_rm  = *.bbl *-blx.bib *.blg
index_rm = *.idx *.ind *.ilg
rm_targets = *.lof *.lot *.lol *.aux *.log *.synctex.gz *.out *.toc *.run.xml

# find recursively all files to remove in subdirectories
rm_files := $(foreach tmp, $(rm_targets), $(shell find -type f -name '$(tmp)'))
biblio_rm_files := $(foreach tmp, $(biblio_rm), $(shell find -type f -name '$(tmp)'))
index_rm_files := $(foreach tmp, $(index_rm), $(shell find -type f -name '$(tmp)'))

# clean up all
clean: biblioclean indexclean
	@ echo -e "\n[`tput bold``tput setab 1`clean`tput sgr0`] `tput bold`rm`tput sgr0` " \
		   "`tput setaf 3`$(rm_options)`tput sgr0` $(rm_targets)\n"
	@ rm $(rm_options) $(rm_files)

# clean up all + .pdf
distclean: clean
	@ echo -e "\n[`tput bold``tput setab 1`distclean`tput sgr0`] `tput bold`rm`tput sgr0` " \
		   "`tput setaf 3`$(rm_options)`tput sgr0` $(document).pdf\n"
	@ rm $(rm_options) $(document).pdf

# clean up bibliography files
biblioclean:
	@ echo -e "\n[`tput bold``tput setab 1`biblio-clean`tput sgr0`] `tput bold`rm`tput sgr0` " \
		   "`tput setaf 3`$(rm_options)`tput sgr0` $(biblio_rm)\n"
	@ rm $(rm_options) $(biblio_rm_files)

# clean up index files
indexclean:
	@ echo -e "\n[`tput bold``tput setab 1`index-clean`tput sgr0`] `tput bold`rm`tput sgr0` " \
		   "`tput setaf 3`$(rm_options)`tput sgr0` $(index_rm)\n"
	@ rm $(rm_options) $(index_rm_files)

# make a package
date = $(strip $(shell date "+%Y.%m.%d" ) )
directory = $(shell pwd)
dist: clean
	cd ..; \
		tar -cvaf appunti_informatica-$(date).tar.gz --exclude-vcs $(directory)/*

%.aux: %.tex Makefile
	@ echo -e "\n >> Updating: `tput setaf 4`$@`tput sgr0`"
	@ echo -e "`tput bold`pdflatex`tput sgr0` $< > `tput setaf 1`/dev/null`tput sgr0`" # creo il target
	@ pdflatex $< > /dev/null # creo il target
	@ echo -e "`tput bold``tput setaf 4``tput setab 5` <<< `tput sgr0`"

#	touch $(patsubst %.tex,%-blx.bib,$<) 

# ############################################################################
#
# BIBLIOGRAPHY
#
# ############################################################################

# This rule will create %.aux file, also
%-blx.bib: %.tex $(bibliografia).bib Makefile
	@ echo -e "\n >> Updating: `tput setaf 4`$@`tput sgr0`"
	@ echo -e "`tput bold`pdflatex`tput sgr0` $< > `tput setaf 1`/dev/null`tput sgr0`" # creo il target
	@ pdflatex $< > /dev/null # creo il target
	@ echo -e "`tput bold``tput setaf 4``tput setab 5` <<< `tput sgr0`"

bibtex = bibtex
%.bbl: %.aux %-blx.bib 
	@ echo -e "\n >> Updating: `tput setaf 4`$@`tput sgr0`"
	@ echo -e "`tput bold`$(bibtex)`tput sgr0` $<\n" #
	@ $(bibtex) $<
	@ echo -e "`tput bold``tput setaf 4``tput setab 5` <<< `tput sgr0`"

# if i put prerequisited in this order, *.aux is compiled only once! :)
biblio: $(document)-blx.bib $(document).bbl

# ############################################################################
#
# INDEX
#
# ############################################################################

%.idx: %.tex Makefile
	@ echo -e "\n >> Updating: `tput setaf 4`$@`tput sgr0`"
	@ echo -e "`tput bold`pdflatex`tput sgr0` $< > `tput setaf 1`/dev/null`tput sgr0`" # creo il target
	@ pdflatex $< > /dev/null # creo il target
	@ echo -e "`tput bold``tput setaf 4``tput setab 5` <<< `tput sgr0`"

makeindex = makeindex
%.ind: %.idx
	@ echo -e "\n >> Updating: `tput setaf 4`$@`tput sgr0`"
	@ echo -e "`tput bold`$(makeindex)`tput sgr0` $<\n"
	@ $(makeindex) $<
	@ echo -e "`tput bold``tput setaf 4``tput setab 5` <<< `tput sgr0`"

index: $(document).idx $(document).ind 

# ############################################################################
#
# WHOLE DOCUMENT
#
# ############################################################################

# One time run
