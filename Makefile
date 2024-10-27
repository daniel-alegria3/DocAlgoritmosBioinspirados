DATA_DIR = ./src/data
GEN_DIR = ./src/generated

output: ${OUTPUT_DEPS}
	tectonic -X build

clean:
	rm -f main.aux main.log main.pyg main.xdv main.out

.PHONY: clean

