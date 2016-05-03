TEX=slides.tex
PDF=$(TEX:.tex=.pdf)
PDFTEX=pdflatex
RM=rm -f

#compile twice to ensure ToC is generated
all:
	$(PDFTEX) $(TEX)
	$(PDFTEX) $(TEX)

clean:
	$(RM) *.aux
	$(RM) *.log
	$(RM) *.nav
	$(RM) *.out
	$(RM) *.snm
	$(RM) *.toc
	$(RM) *.vrb

fclean: clean
	$(RM) $(PDF)

re: fclean all
