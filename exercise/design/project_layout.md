# project layout

Layout also directs development in that:
- Makes work progress separately or parallel
- Shows the overall design 

Parallel or iterative development is the most important in designing
the project layout.

## single tree - playground

- Include are shared for all subprojects except ones under Learn 
- Top level CMakeLists.txt has several executable targets for:
  - Source/Roles folders
- Tests have test projects using the library targets of top level project.

## unit tests

- test folder 
- doctest based
- Use library projects 

## naming

- changed to snake cases except types
  - folders are considered as variables. 
  - filename also


## library projects

- playground_core 
- playground_link
- playground_data
- playground_sim


## cmake configuration

each library is built from its own CMakeLists.txt.

test projects use the libraries.









