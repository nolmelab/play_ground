# Project Layout

Layout also directs development in that:
- Makes work progress separately or parallel
- Shows the overall design 

Parallel or iterative development is the most important in designing
the project layout.

## Single Tree - playground

- Include are shared for all subprojects except ones under Learn 
- Top level CMakeLists.txt has several executable targets for:
  - Source/Roles folders
- Tests have test projects using the library targets of top level project.

## Unit Tests

- Tests folder 
- doctest based
- Use library projects 

## Naming

- changed to snake cases except types
  - folders are considered as variables. 
  - filename also










