#!/usr/bin/env sh
cd ../kysdk-java/
mvn clean install -DskipTests=true --settings ../package/settings.xml
