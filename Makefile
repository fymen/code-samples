# For batch processing

SOURCES = $(wildcard *.org)
PDFS = $(SOURCES:%.org=%.pdf)

all: $(PDFS)

Readme.pdf: Readme.org
	emacs -u "$(id -un)" --batch --eval '(load user-init-file)' $< -f org-latex-export-to-pdf

%.pdf: %.org
	emacs -u "$(id -un)" --batch --eval '(load user-init-file)' $< -f org-beamer-export-to-pdf 

clean:
	rm -rf *~ *.pdf *.tex _minted* *.png
