plugins {
    id("java")
}

group = "io.github.tuilakhanh.Lab05.RMIServer"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(platform("org.junit:junit-bom:5.10.0"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    implementation(files("libs/JLog-1.0-SNAPSHOT.jar"))
}

tasks.test {
    useJUnitPlatform()
}