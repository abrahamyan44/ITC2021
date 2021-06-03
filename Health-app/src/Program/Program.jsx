import React from 'react';
import './Program.css';
import Training from './TrainingCard/TrainingCard';
import NavigationBar from './NavigationBar/NavigationBar';
import {
    mdiRun,
    mdiYoga,
    // mdiPlus,
    // mdiHome,
    // mdiBell,
    // mdiFood,
    // mdiTicket,
    // mdiAccount,
    mdiArmFlex,
    mdiDumbbell,
    // mdiChartLine,
    // mdiChevronRight
  } from '@mdi/js';
  import {
    H4,
    // H5,
    // H6,
    Card,
    // Body2,
    // Caption,
    // Subtitle2,
    IconButton,
    // withResize,
    ToggleButton,
    // ProgressCircular,
  } from 'ui-neumorphism'
import Icon from '@mdi/react';

class Program extends React.Component {
    render() {
        return (
            <Card width={300} height={600}>
                <H4 className='title'>Program</H4>
                <div className='couple-cards'>
                    <Training icon = {mdiArmFlex} title = {'Arm'} subtitle = {'training'} progress = {'In progress..'}/>
                    <Training icon = {mdiDumbbell} title = {'Weight'} subtitle = {'training'} progress = {'Have finished'}/>
                </div>
                <div className='couple-cards'>
                    <Training icon = {mdiRun} title = {'Run'} subtitle = {'training'} progress = {'In progress..'}/>
                    <Training icon = {mdiYoga} title = {'Yoga'} subtitle = {'training'} progress = {'No task'}/>
                </div>
                <H6 className='subtitle'>Courses Collection</H6>
                <NavigationBar />
            </Card>
        )
    }
}

export default Program;
