plugins {
    id("java")
}

group = "io.github.tuilakhanh.Lab05.Corba"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(platform("org.junit:junit-bom:5.10.0"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    implementation("org.jacorb:jacorb:3.9")
    implementation("org.jacorb:jacorb-idl-compiler:3.9")
    implementation(files("libs/JLog-1.0-SNAPSHOT.jar"))
}

tasks.test {
    useJUnitPlatform()
}

tasks.register<JavaExec>("compileIdl")  {
    group = "build"
    description = "Compiles CORBA IDL files to Java"

    val idlDir = file("src/main/idl")
    val javaOutputDir = file("$buildDir/generated/sources/idl/")

    inputs.dir(idlDir)
    outputs.dir(javaOutputDir)

    classpath = sourceSets.main.get().runtimeClasspath
    mainClass.set("org.jacorb.idl.parser")
    args("-d", "$projectDir/src/main/java", "$projectDir/src/main/idl/Calc.idl")
}

sourceSets {
    main {
        java {
            srcDir("$projectDir/src/main/java")
        }
    }
}

tasks.jar {
    dependencies {
        implementation(files("libs/JLog-1.0-SNAPSHOT.jar"))
    }
}