watch:
	ls *.c | entr -s 'pushd builddir; ninja && meson test; popd'
