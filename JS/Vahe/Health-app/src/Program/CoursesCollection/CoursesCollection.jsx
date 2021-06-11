import React from 'react';
import './CoursesCollection.css';
import Icon from '@mdi/react';
import {
    Card,
    Caption,
    Subtitle2,
    IconButton,
  } from 'ui-neumorphism';
import {
    mdiTicket,
    mdiChevronRight
} from '@mdi/js';

class CoursesCollection extends React.Component {
    render() {
        const {dark} = this.props;
        return (
            <Card rounded={false} elevation={2} dark = {dark} className='courses-card'>
                <div className='nested-div'>
                    <Card outlined dark={dark} className='ticket-card'>
                        <Icon path={mdiTicket} size={1.5} dark = {dark}  color='var(--primary)'/>
                    </Card>
                    <Card flat dark={dark} className='text-card-courses'>
                        <Subtitle2 className='title-course'>Courses I attended</Subtitle2>
                        <Card flat className='card1'>
                            <Caption secondary dark = {dark} component='span'>11 courses in total</Caption>
                            <IconButton text={false} dark={dark} size='small' rounded className='icon-button'>
                                <Icon path={mdiChevronRight} size={0.7} color='var(--primary)'/>
                            </IconButton>
                        </Card>
                    </Card>
                </div>
            </Card>
        )
    }

}

export default CoursesCollection;