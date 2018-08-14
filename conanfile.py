from conans import ConanFile, CMake, tools


class ConfigExConan(ConanFile):
    name = "ConfigEx"
    version = "1.0.0"
    requires = 'boost/1.67@conan/stable'
    license = "MIT"
    url = "https://github.com/microblink/config_ex"
    generators = "cmake"
    scm = {
        "type": "git",
        "url": "auto",
        "revision": "auto"
    }
    no_copy_source = True

    def configure(self):
        self.options['boost'].header_only = True

    def package(self):
        self.copy("include/*.hpp")

    def package_id(self):
        self.info.header_only()

