# download dependencies

system("svn export https://github.com/JamesYang007/FastAD/trunk/include/fastad_bits inst/include/fastad_bits --force")
system("wget -O inst/include/fastad.h https://raw.githubusercontent.com/JamesYang007/FastAD/master/include/fastad")

# replace Eigen/Core by RcppEigen.h
files <- fs::dir_ls("inst/include", recurse = TRUE, type = "file")
for (file in files) {
  lines <- readLines(file)
  line <- paste0(lines, collapse = "\n")
  if (grepl("<Eigen", line, fixed = TRUE)) {
    # print(file)
    # there are <Eigen/Core> or <Eigen/Dense> to be replaced
    lines[grepl("#include <Eigen/Core>", lines, fixed = TRUE)] <- "#include <RcppEigen.h>"
    lines[grepl("#include <Eigen/Dense>", lines, fixed = TRUE)] <- "#include <RcppEigen.h>"
    writeLines(lines, file)
  }
}
