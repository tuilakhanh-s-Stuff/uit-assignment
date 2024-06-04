plugins {
    id("java")
}

group = "io.github.tuilakhanh.Lab01"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(platform("org.junit:junit-bom:5.9.1"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    implementation(files("libs/JLog-1.0-SNAPSHOT.jar"))
}


tasks.test {
    useJUnitPlatform()
}

tasks.jar {
    manifest {
        attributes["Main-Class"] = "io.github.tuilakhanh.Lab01.Main"
    }
    dependencies {
        implementation(files("libs/JLog-1.0-SNAPSHOT.jar"))
    }
}