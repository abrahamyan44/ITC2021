import React from 'react';
import './Program.css';
import Training from './TrainingCard/TrainingCard';
import NavigationBar from '../NavigationBar/NavigationBar';
import CoursesCollection from './CoursesCollection/CoursesCollection';
import {
    mdiRun,
    mdiYoga,
    mdiArmFlex,
    mdiDumbbell,
  } from '@mdi/js';
  import {
    H4,
    H6,
    Card,
  } from 'ui-neumorphism'
import { withRouter } from 'react-router';

class Program extends React.Component {
    render() {
        const {dark} = this.props;
        return (
            <>
            {/* <Card rounded width={300} height={600} dark = {dark} className='program-card'> */}
                <H4 className='title-program' dark = {dark}>Program</H4>
                <div className='couple-cards'>
                    <Training dark = {dark} icon = {mdiArmFlex} title = {'Arm'} subtitle = {'training'} progress = {'In progress..'}/>
                    <Training dark = {dark} icon = {mdiDumbbell} title = {'Weight'} subtitle = {'training'} progress = {'Have finished'}/>
                </div>
                <div className='couple-cards'>
                    <Training dark = {dark} icon = {mdiRun} title = {'Run'} subtitle = {'training'} progress = {'In progress..'}/>
                    <Training dark = {dark} icon = {mdiYoga} title = {'Yoga'} subtitle = {'training'} progress = {'No task'}/>
                </div>
                <H6 className='subtitle' dark = {dark}>Courses Collection</H6>
                <CoursesCollection dark = {dark}/>
                {/* <NavigationBar dark = {dark} selected = {'Program'} /> */}
            {/* </Card> */}
            </>
        )
    }
}

export default withRouter(Program);
